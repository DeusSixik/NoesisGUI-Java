import dev.sixik.noesisgui.NoesisGui;
import dev.sixik.noesisgui.nsgui.*;
import dev.sixik.noesisgui.nshandlers.NSEventHandlerManager;
import dev.sixik.noesisgui_impl.NSThemes;
import dev.sixik.noesisgui_ini.NoesisGuiJava;
import dev.sixik.noesisgui_render.gl.NSOpenGl;
import org.lwjgl.glfw.GLFW;
import org.lwjgl.opengl.GL;
import org.lwjgl.opengl.GL11;

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
        noesisInit();        // аналог NoesisInit() — тут будут твои JNI вызовы

        loop();

        cleanup();
    }

    ////////////////////////////////////////////////////////////////////////////////
    // Инициализация GLFW + создание окна
    ////////////////////////////////////////////////////////////////////////////////
    private void initWindow() {
        if (!glfwInit()) {
            throw new IllegalStateException("Unable to initialize GLFW");
        }

        // Настройки контекста (можешь подправить под нужную версию GL)
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE); // для macOS

        // С трафаретом (GLUT_STENCIL)
        glfwWindowHint(GLFW_STENCIL_BITS, 8);

        window = glfwCreateWindow(width, height, "NoesisGUI - LWJGL integration", 0, 0);
        if (window == 0L) {
            throw new RuntimeException("Failed to create GLFW window");
        }

        glfwMakeContextCurrent(window);
        glfwSwapInterval(1); // VSync

        // Callbacks — аналоги ReshapeFunc / MouseMoveFunc / MouseFunc
        setupCallbacks();
    }

    private void initOpenGL() {
        // Очень важно: создаём OpenGL capabilities после makeContextCurrent
        GL.createCapabilities();

        glViewport(0, 0, width, height);
    }

    ////////////////////////////////////////////////////////////////////////////////
    // Callbacks — соответствие GLUT -> GLFW
    ////////////////////////////////////////////////////////////////////////////////
    private void setupCallbacks() {
        // ReshapeFunc(int width, int height)
        glfwSetFramebufferSizeCallback(window, (win, w, h) -> {
            width = w;
            height = h;
            glViewport(0, 0, width, height);

            // здесь аналог _view->SetSize(width, height);
            noesisResize(width, height);
        });

        // MouseMoveFunc(int x, int y)
        glfwSetCursorPosCallback(window, (win, xpos, ypos) -> {
            // GLFW координаты double, Noesis ожидает int
            int x = (int) xpos;
            int y = (int) ypos;
            noesisMouseMove(x, y);
        });

        // MouseFunc(int button, int state, int x, int y)
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
    // Главный цикл — аналог DisplayFunc + glutMainLoop()
    ////////////////////////////////////////////////////////////////////////////////
    private void loop() {
        // аналог glutGet(GLUT_ELAPSED_TIME)/1000.0f
        double appStartTime = glfwGetTime();

        while (!glfwWindowShouldClose(window)) {
            double timeSeconds = glfwGetTime() - appStartTime;

            // ----- Noesis update / offscreen -----
            // _view->Update(t)
            // _view->GetRenderer()->UpdateRenderTree();
            // _view->GetRenderer()->RenderOffscreen();
            noesisUpdate(timeSeconds);
            noesisRenderOffscreen();

            // ----- Восстанавливаем состояние GL, как в примере -----
            glBindFramebuffer(GL_FRAMEBUFFER, 0);
            glViewport(0, 0, width, height);
            glDisable(GL_SCISSOR_TEST);

            glColorMask(true, true, true, true);
            glClearColor(0.0f, 0.0f, 0.25f, 0.0f);
            glClearStencil(0);
            glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

            // ----- On-screen render -----
            // _view->GetRenderer()->Render();
            noesisRenderOnscreen();

            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }

    ////////////////////////////////////////////////////////////////////////////////
    // Заглушки под JNI — сюда ты подставишь реальные вызовы Noesis
    ////////////////////////////////////////////////////////////////////////////////

    private void noesisInit() {
        NoesisGuiJava.Initialize();

        NoesisGui.init();

        NoesisGui.setThemeProviders();
        NoesisGui.loadApplicationResources(NSThemes.darkBlue());

        NSFrameworkElement data = NoesisGui.parseXaml("""
                <Grid xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
                             xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">
                         <Grid.Background>
                           <LinearGradientBrush StartPoint="0,0" EndPoint="0,1">
                             <GradientStop Offset="0" Color="#FF123F61"/>
                             <GradientStop Offset="0.6" Color="#FF0E4B79"/>
                             <GradientStop Offset="0.7" Color="#FF106097"/>
                           </LinearGradientBrush>
                         </Grid.Background>
                
                         <Viewbox>
                           <StackPanel Margin="50">
                             <!-- вот тут даём идентификатор -->
                             <Button x:Name="HelloButton"
                                     Content="Hello World!"
                                     Margin="0,30,0,0"/>
                             <Rectangle Height="5" Margin="-10,20,-10,0">
                               <Rectangle.Fill>
                                 <RadialGradientBrush>
                                   <GradientStop Offset="0" Color="#40000000"/>
                                   <GradientStop Offset="1" Color="#00000000"/>
                                 </RadialGradientBrush>
                               </Rectangle.Fill>
                             </Rectangle>
                           </StackPanel>
                         </Viewbox>
                       </Grid>
                """);
        _view = NoesisGui.createView(data);
        _view.setFlags(NSGui_RenderFlags.PPAA.value | NSGui_RenderFlags.LCD.value);
        _view.getRenderer().init(NSOpenGl.createDevice(false));
        _view.setSize(width, height);

        NSEventHandlerManager.subscribe(_view, "HelloButton", (args) -> {
            System.out.println(args.getRoutedEvent().getName());
        });
        // Здесь должен быть твой JNI-бинд:
        // - SetLogHandler
        // - SetLicense
        // - GUI::Init()
        // - ThemeProviders
        // - ParseXaml(...)
        // - CreateView(...)
        // - _view->SetFlags(...)
        // - _view->GetRenderer()->Init(GLFactory::CreateDevice(...))
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
    // Завершение
    ////////////////////////////////////////////////////////////////////////////////
    private void cleanup() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }
}
