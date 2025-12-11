import dev.sixik.noesisgui.NoesisGui;
import dev.sixik.noesisgui.nsdrawing.NSColor;
import dev.sixik.noesisgui.nsdrawing.NSPoint;
import dev.sixik.noesisgui.nsgui.*;
import dev.sixik.noesisgui.nshandlers.NSEventHandlerManager;
import dev.sixik.noesisgui_impl.NSThemes;
import dev.sixik.noesisgui_ini.KeyValueParser;
import dev.sixik.noesisgui_ini.NoesisGuiJava;
import dev.sixik.noesisgui_render.gl.NSOpenGl;
import org.lwjgl.opengl.GL;

import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

import static dev.sixik.noesisgui.nsgui.NSGui_MouseButton.MouseButton_Left;
import static org.lwjgl.glfw.GLFW.*;
import static org.lwjgl.opengl.GL11.*;
import static org.lwjgl.opengl.GL30.GL_FRAMEBUFFER;
import static org.lwjgl.opengl.GL30.glBindFramebuffer;

public final class LwjglNoesisDemo {

    private long window;

    private int width = 1000;
    private int height = 600;
    private NSIView _view;

    public static void main(String[] args) {
        new LwjglNoesisDemo().run();
    }

    private void run() {
        initWindow();
        initOpenGL();
        noesisInit();

        loop();

        cleanup();
    }

    ////////////////////////////////////////////////////////////////////////////////
    private void initWindow() {
        if (!glfwInit()) {
            throw new IllegalStateException("Unable to initialize GLFW");
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE); // для macOS

        glfwWindowHint(GLFW_STENCIL_BITS, 8);

        window = glfwCreateWindow(width, height, "NoesisGUI - LWJGL integration", 0, 0);
        if (window == 0L) {
            throw new RuntimeException("Failed to create GLFW window");
        }

        glfwMakeContextCurrent(window);
        glfwSwapInterval(1); // VSync

        setupCallbacks();
    }

    private void initOpenGL() {
        GL.createCapabilities();

        glViewport(0, 0, width, height);
    }

    ////////////////////////////////////////////////////////////////////////////////
    private void setupCallbacks() {
        glfwSetFramebufferSizeCallback(window, (win, w, h) -> {
            width = w;
            height = h;
            glViewport(0, 0, width, height);

            noesisResize(width, height);
        });

        glfwSetCursorPosCallback(window, (win, xpos, ypos) -> {
            int x = (int) xpos;
            int y = (int) ypos;
            noesisMouseMove(x, y);
        });

        glfwSetMouseButtonCallback(window, (win, button, action, mods) -> {
            double xpos[] = new double[1];
            double ypos[] = new double[1];
            glfwGetCursorPos(win, xpos, ypos);
            int x = (int) xpos[0];
            int y = (int) ypos[0];

            if (button == GLFW_MOUSE_BUTTON_LEFT) {
                if (action == GLFW_PRESS) {
                    noesisMouseButtonDown(x, y);
                } else if (action == GLFW_RELEASE) {
                    noesisMouseButtonUp(x, y);
                }
            }
        });
    }

    ////////////////////////////////////////////////////////////////////////////////
    private void loop() {
        double appStartTime = glfwGetTime();

        while (!glfwWindowShouldClose(window)) {
            double timeSeconds = glfwGetTime() - appStartTime;

            noesisUpdate(timeSeconds);
            noesisRenderOffscreen();

            glBindFramebuffer(GL_FRAMEBUFFER, 0);
            glViewport(0, 0, width, height);
            glDisable(GL_SCISSOR_TEST);

            glColorMask(true, true, true, true);
            glClearColor(0.0f, 0.0f, 0.25f, 0.0f);
            glClearStencil(0);
            glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

            noesisRenderOnscreen();

            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }

    ////////////////////////////////////////////////////////////////////////////////
    private void noesisInit() {
        NoesisGuiJava.Initialize();

        NoesisGui.setLogHandler(((file, line, level, channel, message) -> {
            System.out.println("[NOESIS] " + file + ":" + line + " [" + NoesisGui.getLogLevelName((int) level) + "] " + channel + " - " + message);
        }));

        Map<String, String> licences = new HashMap<>();

        try {
            licences = KeyValueParser.parseFile(".noesis_licence");
        } catch (IOException e) {
            System.out.println("Error parse Licence file: .noesis_licence");
        }

        if(!licences.isEmpty())
            NoesisGui.setLicense(licences.get("NAME"), licences.get("KEY"));

        NoesisGui.init();

        NoesisGui.setThemeProviders();
        NoesisGui.loadApplicationResources(NSThemes.darkBlue());

        _view = NoesisGui.createView(createCode());
        _view.setFlags(NSGui_RenderFlags.PPAA.value | NSGui_RenderFlags.LCD.value);
        _view.getRenderer().init(NSOpenGl.createDevice(false));
        _view.setSize(width, height);

        final NSFrameworkElement root = _view.getContent();
    }

    private void noesisResize(int w, int h) {
        _view.setSize(w, h);
    }

    private void noesisMouseMove(int x, int y) {
        _view.mouseMove(x, y);
    }

    private void noesisMouseButtonDown(int x, int y) {
        _view.mouseButtonDown(x, y, MouseButton_Left);
    }

    private void noesisMouseButtonUp(int x, int y) {
        _view.mouseButtonUp(x, y, MouseButton_Left);
    }

    private void noesisUpdate(double timeSeconds) {
        _view.update(timeSeconds);
    }

    private void noesisRenderOffscreen() {
         _view.getRenderer().updateRenderTree();
         _view.getRenderer().renderOffscreen();
    }

    private void noesisRenderOnscreen() {
        _view.getRenderer().render();
    }


    ////////////////////////////////////////////////////////////////////////////////
    private void cleanup() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    private static NSFrameworkElement createCode() {
        NSRadialGradientBrush brush = new NSRadialGradientBrush();
        brush.setCenter(new NSPoint(.5f, .5f));
        brush.setGradientOrigin(new NSPoint(.5f, .5f));
        brush.setRadiusY(.5f);
        brush.setRadiusX(.5f);

        NSGradientStopCollection stops = new NSGradientStopCollection();

        NSGradientStop inner = new NSGradientStop(new NSColor(255, 255, 255, 255), 0);
        stops.add(inner);

        NSGradientStop outer = new NSGradientStop(new NSColor(255, 255, 255, 0), 1f);
        stops.add(outer);
        brush.setGradientStops(stops);

        NSGrid root = new NSGrid();
        root.setWidth(400f);
        root.setHeight(300f);
        root.setBackground(brush);
        root.setMargin(new NSThickness(50, 0, 0, 10));



        return root;
    }

    private static NSFrameworkElement createDefault() {
        return NoesisGui.parseXaml("""
<Grid xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
      xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">

    <!-- Главное меню -->
    <Grid x:Name="MainMenuRoot">
        <StackPanel HorizontalAlignment="Center" VerticalAlignment="Center">
            <Button x:Name="PlayButton" ToolTip="Окно настроек" Content="Play" Width="200" Margin="0,0,0,10"/>
            <Button x:Name="SettingsButton" Content="Settings" Width="200" Margin="0,0,0,10"/>
            <Button x:Name="ExitButton" Content="Exit" Width="200"/>
        </StackPanel>
    </Grid>

    <!-- Окно настроек поверх -->
    <Grid x:Name="SettingsRoot"
          Background="#80000000"
          Visibility="Collapsed">
        <Border Width="400" Height="300" Background="#FF202020" CornerRadius="8"
                HorizontalAlignment="Center" VerticalAlignment="Center">
            <StackPanel Margin="20">
                <TextBlock Text="Settings" FontSize="24" Margin="0,0,0,10"/>
                <!-- тут всякие ползунки, чекбоксы -->
                <Button x:Name="SettingsCloseButton"
                        Content="Back"
                        HorizontalAlignment="Right"
                        Margin="0,20,0,0"/>
            </StackPanel>
        </Border>
    </Grid>
</Grid>
                """);
    }
}
