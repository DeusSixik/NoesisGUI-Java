import dev.sixik.noesisgui.NoesisGui;
import dev.sixik.noesisgui.nsapp.NsNotifyPropertyChangedBase;
import dev.sixik.noesisgui.nscore.NSBaseComponent;
import dev.sixik.noesisgui.nsdrawing.NSColor;
import dev.sixik.noesisgui.nsdrawing.NSPoint;
import dev.sixik.noesisgui.nsgui.*;
import dev.sixik.noesisgui.nshandlers.NSEventHandlerManager;
import dev.sixik.noesisgui_impl.NSThemes;
import dev.sixik.noesisgui_impl.NoesisGuiWidgets;
import dev.sixik.noesisgui_ini.KeyValueParser;
import dev.sixik.noesisgui_ini.NoesisGuiJava;
import dev.sixik.noesisgui_render.gl.NSOpenGl;
import dev.sixik.noesisgui_render.lwgl.NoesisGlfwKeyMap;
import org.lwjgl.glfw.GLFW;
import org.lwjgl.opengl.GL;

import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.function.Function;

import static dev.sixik.noesisgui.nsgui.NSGui_MouseButton.MouseButton_Left;
import static org.lwjgl.glfw.GLFW.*;
import static org.lwjgl.opengl.GL11.*;
import static org.lwjgl.opengl.GL30.GL_FRAMEBUFFER;
import static org.lwjgl.opengl.GL30.glBindFramebuffer;

public final class LwjglNoesisDemo {


    private NSFrameworkElement root;

    private NSToggleButton navControls, navMobs, navTheme, navAnim, navLog;
    private NSGrid pageControls, pageMobs, pageTheme, pageAnim, pageLog;

    private NSTextBlock titleRight, fpsText, memText, lastEvent, mobCount, txtEcho, statsText;
    private NSTextBox mobSearch, txtInput;
    private NSSlider sliderValue, hue;
    private NSProgressBar progressValue;
    private NSWrapPanel mobWrap; // если у тебя WrapPanel класс называется иначе — замени
    private NSButton btnPrimary, btnSecondary, btnApplyTheme, btnPlayAnim, btnClearLog;
    private NSHyperlink linkNoesis;
//    private NSListBox logList;

    private boolean navGuard = false;


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

        glfwSetKeyCallback(window, (w, key, scancode, action, mods) -> {
            final var noesis_key = NoesisGlfwKeyMap.toNoesisKey(key);

            if (action == GLFW_PRESS) {
                _view.keyDown(noesis_key);
            } else if (action == GLFW_RELEASE) {
                _view.keyUp(noesis_key);
            } else if (action == GLFW_REPEAT) {
                _view.keyDown(noesis_key);
            }
        });

        glfwSetCharCallback(window, (w, codepoint) -> {
            _view.charEvent(codepoint);
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

    private int mapKey(int glfwKey) {
        return switch (glfwKey) {
            case GLFW_KEY_ENTER -> NSGui_Key.RETURN.value;
            case GLFW_KEY_BACKSPACE -> NSGui_Key.BACK.value;
            case GLFW_KEY_TAB -> NSGui_Key.TAB.value;
            case GLFW_KEY_LEFT -> NSGui_Key.LEFT.value;
            case GLFW_KEY_RIGHT -> NSGui_Key.RIGHT.value;
            case GLFW_KEY_UP -> NSGui_Key.UP.value;
            case GLFW_KEY_DOWN -> NSGui_Key.DOWN.value;
            default -> -1;
        };
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

        final var root = createDefault();
        wireUi(root);
        _view = NoesisGui.createView(root);
        _view.setFlags(NSGui_RenderFlags.PPAA.value | NSGui_RenderFlags.LCD.value);
        _view.getRenderer().init(NSOpenGl.createDevice(false));
        _view.setSize(width, height);
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

        final NSTextBlock tb = new NSTextBlock();

        final var lint = new NSHyperlink();
        lint.setNavigateUri("https://example.com");

        final var run = new NSRun();
        run.setText("Open website ");

        final var list = tb.getInlines();
        lint.getInlines().add(run);

        {
            var r1 = new NSRun(); r1.setText("Go to");
            var r2 = new NSRun(); r2.setText("!");

            list.add(r1);
            list.add(lint);
            list.add(r2);
        }

        lint.requestNavigateEvent(((component, args) -> {
            System.out.println(args.uri);
        }));

        tb.setBackground(NSBrushes.Red());
        root.getChildren().add(tb);

        return root;
    }

    private static NSFrameworkElement createDefault() {
        return NoesisGui.parseXaml("""
<Grid xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
      xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
      Background="#AA0B0F14">

  <Grid.Resources>
    <SolidColorBrush x:Key="Bg" Color="#AA0B0F14"/>
    <SolidColorBrush x:Key="Card" Color="#CC151B24"/>
    <SolidColorBrush x:Key="Stroke" Color="#332A3445"/>
    <SolidColorBrush x:Key="Accent" Color="#FF3B82F6"/>
    <SolidColorBrush x:Key="Text" Color="#FFE5E7EB"/>
    <SolidColorBrush x:Key="TextDim" Color="#FF9CA3AF"/>

    <Style TargetType="TextBlock">
      <Setter Property="Foreground" Value="{StaticResource Text}"/>
      <Setter Property="FontSize" Value="16"/>
    </Style>

    <Style x:Key="H1" TargetType="TextBlock">
      <Setter Property="FontSize" Value="26"/>
      <Setter Property="FontWeight" Value="SemiBold"/>
    </Style>

    <Style x:Key="CardBorder" TargetType="Border">
      <Setter Property="Background" Value="{StaticResource Card}"/>
      <Setter Property="BorderBrush" Value="{StaticResource Stroke}"/>
      <Setter Property="BorderThickness" Value="1"/>
      <Setter Property="CornerRadius" Value="14"/>
      <Setter Property="Padding" Value="14"/>
      <Setter Property="Margin" Value="0,0,0,12"/>
    </Style>

    <Style TargetType="Button">
      <Setter Property="Padding" Value="12,8"/>
      <Setter Property="Background" Value="#222A3445"/>
      <Setter Property="Foreground" Value="{StaticResource Text}"/>
      <Setter Property="BorderBrush" Value="{StaticResource Stroke}"/>
      <Setter Property="BorderThickness" Value="1"/>
      <Setter Property="Margin" Value="0,0,0,8"/>
    </Style>

    <Style x:Key="NavButton" TargetType="ToggleButton">
      <Setter Property="Padding" Value="12,10"/>
      <Setter Property="Foreground" Value="{StaticResource Text}"/>
      <Setter Property="Background" Value="#00000000"/>
      <Setter Property="BorderBrush" Value="#00000000"/>
      <Setter Property="BorderThickness" Value="0"/>
      <Setter Property="HorizontalContentAlignment" Value="Left"/>
      <Setter Property="Margin" Value="0,0,0,6"/>
    </Style>

    <Style x:Key="PrimaryButton" TargetType="Button" BasedOn="{StaticResource {x:Type Button}}">
      <Setter Property="Background" Value="{StaticResource Accent}"/>
      <Setter Property="BorderBrush" Value="#00000000"/>
    </Style>
  </Grid.Resources>

  <Grid.ColumnDefinitions>
    <ColumnDefinition Width="260"/>
    <ColumnDefinition Width="*"/>
  </Grid.ColumnDefinitions>

  <!-- Left nav -->
  <Border Background="#CC0E141E" BorderBrush="{StaticResource Stroke}" BorderThickness="0,0,1,0">
    <StackPanel Margin="16">
      <TextBlock Style="{StaticResource H1}" Text="Noesis Demo"/>
      <TextBlock Foreground="{StaticResource TextDim}" Margin="0,6,0,16"
                 Text="Minecraft integration showcase"/>

      <ToggleButton x:Name="NavControls" Style="{StaticResource NavButton}" Content="Controls"/>
      <ToggleButton x:Name="NavMobs"     Style="{StaticResource NavButton}" Content="Mob Tiles"/>
      <ToggleButton x:Name="NavTheme"    Style="{StaticResource NavButton}" Content="Themes"/>
      <ToggleButton x:Name="NavAnim"     Style="{StaticResource NavButton}" Content="Animations"/>
      <ToggleButton x:Name="NavLog"      Style="{StaticResource NavButton}" Content="Log"/>

      <Border Margin="0,14,0,0" Background="#33111827" CornerRadius="12" Padding="12">
        <StackPanel>
          <TextBlock Text="Hint" />
          <TextBlock Foreground="{StaticResource TextDim}" FontSize="13"
                     Text="Esc — close, колесо — scroll"/>
        </StackPanel>
      </Border>
    </StackPanel>
  </Border>

  <!-- Right content -->
  <Grid Grid.Column="1" Margin="18">
    <Grid.RowDefinitions>
      <RowDefinition Height="Auto"/>
      <RowDefinition Height="*"/>
    </Grid.RowDefinitions>

    <!-- Top bar -->
    <DockPanel Margin="0,0,0,12">
      <TextBlock x:Name="TitleRight" Text="Controls" Style="{StaticResource H1}" />
      <StackPanel Orientation="Horizontal" HorizontalAlignment="Right">
        <TextBlock x:Name="FpsText" Foreground="{StaticResource TextDim}" Margin="0,6,12,0" Text="FPS: -"/>
        <TextBlock x:Name="MemText" Foreground="{StaticResource TextDim}" Margin="0,6,0,0"  Text="Mem: -"/>
      </StackPanel>
    </DockPanel>

    <!-- Pages host -->
    <Grid Grid.Row="1" x:Name="PagesHost">

      <!-- PAGE: Controls -->
      <Grid x:Name="PageControls" Visibility="Visible">
        <StackPanel>
          <TextBlock Style="{StaticResource H1}" Text="Controls and Events"/>
          <TextBlock Foreground="{StaticResource TextDim}" Margin="0,6,0,14"
                     Text="Ручное управление без биндингов." />

          <Border Style="{StaticResource CardBorder}">
            <Grid>
              <Grid.ColumnDefinitions>
                <ColumnDefinition Width="*"/>
                <ColumnDefinition Width="*"/>
              </Grid.ColumnDefinitions>

              <StackPanel Margin="0,0,10,0">
                <TextBlock Text="Buttons"/>
                <Button x:Name="BtnPrimary" Style="{StaticResource PrimaryButton}" Content="Primary Action"/>
                <Button x:Name="BtnSecondary" Content="Secondary Action"/>

                <TextBlock Margin="0,12,0,0" Text="Slider / Progress"/>
                <Slider x:Name="SliderValue" Minimum="0" Maximum="100" Value="25"/>
                <ProgressBar x:Name="ProgressValue" Height="14" Value="25" Maximum="100"/>
              </StackPanel>

              <StackPanel Grid.Column="1" Margin="10,0,0,0">
                <TextBlock Text="Text input"/>
                <TextBox x:Name="TxtInput" Height="34" Text="hello"/>
                <TextBlock x:Name="TxtEcho" Foreground="{StaticResource TextDim}" Margin="0,6,0,0" Text="echo..."/>

                <TextBlock Margin="0,12,0,0" Text="Hyperlink (event)"/>
                <TextBlock>
                  <Run Text="Docs: "/>
                  <Hyperlink x:Name="LinkNoesis" NavigateUri="https://www.noesisengine.com">
                    Noesis Engine
                  </Hyperlink>
                </TextBlock>

                <TextBlock Margin="0,14,0,0" Text="Last event"/>
                <Border Background="#33111827" Padding="10" CornerRadius="10">
                  <TextBlock x:Name="LastEvent" Text="-" Foreground="{StaticResource TextDim}"/>
                </Border>
              </StackPanel>

            </Grid>
          </Border>
        </StackPanel>
      </Grid>

      <!-- PAGE: Mobs -->
      <Grid x:Name="PageMobs" Visibility="Collapsed">
        <StackPanel>
          <TextBlock Style="{StaticResource H1}" Text="Mob Tiles (Search + Spawn)"/>
          <TextBlock Foreground="{StaticResource TextDim}" Margin="0,6,0,14"
                     Text="Плитки заполняются кодом." />

          <Border Style="{StaticResource CardBorder}">
            <Grid>
              <Grid.RowDefinitions>
                <RowDefinition Height="Auto"/>
                <RowDefinition Height="*"/>
              </Grid.RowDefinitions>

              <DockPanel>
                <TextBox x:Name="MobSearch" Width="340" Height="34" Text=""/>
                <TextBlock x:Name="MobCount" Foreground="{StaticResource TextDim}" Margin="12,6,0,0" Text="0 mobs"/>
              </DockPanel>

              <ScrollViewer Grid.Row="1" Margin="0,12,0,0">
                <WrapPanel x:Name="MobWrap" ItemWidth="150" ItemHeight="178"/>
              </ScrollViewer>
            </Grid>
          </Border>
        </StackPanel>
      </Grid>

      <!-- PAGE: Theme -->
      <Grid x:Name="PageTheme" Visibility="Collapsed">
        <StackPanel>
          <TextBlock Style="{StaticResource H1}" Text="Themes / Styles"/>
          <Border Style="{StaticResource CardBorder}">
            <StackPanel>
              <TextBlock Text="Hue"/>
              <Slider x:Name="Hue" Minimum="0" Maximum="360" Value="210"/>
              <Button x:Name="BtnApplyTheme" Style="{StaticResource PrimaryButton}" Content="Apply Theme"/>
            </StackPanel>
          </Border>
        </StackPanel>
      </Grid>

      <!-- PAGE: Anim -->
      <Grid x:Name="PageAnim" Visibility="Collapsed">
        <StackPanel>
          <TextBlock Style="{StaticResource H1}" Text="Animations"/>
          <Border Style="{StaticResource CardBorder}">
            <Grid>
              <Grid.ColumnDefinitions>
                <ColumnDefinition Width="*"/>
                <ColumnDefinition Width="Auto"/>
              </Grid.ColumnDefinitions>

              <Border x:Name="AnimCard" Background="#3322C55E" CornerRadius="14" Padding="18">
                <StackPanel>
                  <TextBlock Text="Animated card"/>
                  <TextBlock Foreground="{StaticResource TextDim}" Margin="0,6,0,0"
                             Text="Запускаем анимацию вручную."/>
                </StackPanel>
              </Border>

              <Button x:Name="BtnPlayAnim" Grid.Column="1" Margin="12,0,0,0" Content="Play"/>
            </Grid>
          </Border>
        </StackPanel>
      </Grid>

      <!-- PAGE: Log -->
      <Grid x:Name="PageLog" Visibility="Collapsed">
        <StackPanel>
          <TextBlock Style="{StaticResource H1}" Text="Log / Diagnostics"/>
          <Border Style="{StaticResource CardBorder}">
            <Grid>
              <Grid.RowDefinitions>
                <RowDefinition Height="Auto"/>
                <RowDefinition Height="*"/>
              </Grid.RowDefinitions>

              <DockPanel>
                <Button x:Name="BtnClearLog" Content="Clear"/>
                <TextBlock x:Name="StatsText" Foreground="{StaticResource TextDim}" Margin="12,6,0,0" Text="..."/>
              </DockPanel>

              <ListBox x:Name="LogList" Grid.Row="1" Margin="0,12,0,0"/>
            </Grid>
          </Border>
        </StackPanel>
      </Grid>

    </Grid>
  </Grid>
</Grid>
""");
    }

    private <T extends NSBaseComponent> T n(String name, Function<Long, T> tClass) {
        return root.findName(name).castTo(tClass);
    }

    private void wireUi(NSFrameworkElement root) {
        this.root = root;

        // nav
        navControls = n("NavControls", NSToggleButton::new);
        navMobs     = n("NavMobs", NSToggleButton::new);
        navTheme    = n("NavTheme", NSToggleButton::new);
        navAnim     = n("NavAnim", NSToggleButton::new);
        navLog      = n("NavLog", NSToggleButton::new);

        // pages
        pageControls = n("PageControls", NSGrid::new);
        pageMobs     = n("PageMobs", NSGrid::new);
        pageTheme    = n("PageTheme", NSGrid::new);
        pageAnim     = n("PageAnim", NSGrid::new);
        pageLog      = n("PageLog", NSGrid::new);

        // topbar
        titleRight = n("TitleRight", NSTextBlock::new);
        fpsText    = n("FpsText", NSTextBlock::new);
        memText    = n("MemText", NSTextBlock::new);

        // controls page
        btnPrimary    = n("BtnPrimary", NSButton::new);
        btnSecondary  = n("BtnSecondary", NSButton::new);
        sliderValue   = n("SliderValue", NSSlider::new);
        progressValue = n("ProgressValue", NSProgressBar::new);
        txtInput      = n("TxtInput", NSTextBox::new);
        txtEcho       = n("TxtEcho", NSTextBlock::new);
        lastEvent     = n("LastEvent", NSTextBlock::new);
        linkNoesis    = n("LinkNoesis", NSHyperlink::new);

        // mobs page
        mobSearch = n("MobSearch", NSTextBox::new);
        mobCount  = n("MobCount", NSTextBlock::new);
        mobWrap   = n("MobWrap", NSWrapPanel::new);

        // theme / anim / log
        hue          = n("Hue", NSSlider::new);
        btnApplyTheme= n("BtnApplyTheme", NSButton::new);
        btnPlayAnim  = n("BtnPlayAnim", NSButton::new);
        btnClearLog  = n("BtnClearLog", NSButton::new);
        statsText    = n("StatsText", NSTextBlock::new);
//        logList      = n("LogList");

        // --- NAV events ---
        navControls.checkedEvent((c, a) -> selectPage("Controls"));
        navMobs.checkedEvent((c, a) -> selectPage("Mobs"));
        navTheme.checkedEvent((c, a) -> selectPage("Theme"));
        navAnim.checkedEvent((c, a) -> selectPage("Anim"));
        navLog.checkedEvent((c, a) -> selectPage("Log"));

        // --- Controls events (пример) ---
        btnPrimary.clickEvent((c, a) -> setLast("Primary clicked"));
        btnSecondary.clickEvent((c, a) -> setLast("Secondary clicked"));

        sliderValue.valueChangedEvent((c, a) -> {
            float v = sliderValue.getValue();
            progressValue.setValue(v);
            setLast("Slider = " + (int)v);
        });

        txtInput.textChangedEvent((c, a) -> {
            txtEcho.setText("echo: " + txtInput.getText());
        });

        linkNoesis.requestNavigateEvent((c, a) -> {
            setLast("Navigate: " + a.uri);
            System.out.println("Open url: " + a.uri);
        });

        btnClearLog.clickEvent((c, a) -> {
//            logList.getItems().clear();
            setLast("Log cleared");
        });

        btnApplyTheme.clickEvent((c, a) -> {
            setLast("Apply theme (hue=" + (int)hue.getValue() + ")");
            // тут ты можешь менять кисти/ресурсы вручную, если хочешь
        });

        btnPlayAnim.clickEvent((c, a) -> {
            setLast("Play anim");
            // тут руками запускаешь storyboard/анимацию (если у тебя уже есть wrapper)
        });

        // заполнить мобов (пример)
        fillMobsExample();

        // initial page
        selectPage("Controls");
    }

    private void setLast(String s) {
        lastEvent.setText(s);
        // можно ещё в лог добавлять:
//        logList.getItems().add(s);
    }

    private void selectPage(String page) {
        if (navGuard) return;
        navGuard = true;

        // скрыть все
        pageControls.setVisibility(NSGui_Visibility.Collapsed);
        pageMobs.setVisibility(NSGui_Visibility.Collapsed);
        pageTheme.setVisibility(NSGui_Visibility.Collapsed);
        pageAnim.setVisibility(NSGui_Visibility.Collapsed);
        pageLog.setVisibility(NSGui_Visibility.Collapsed);

        // снять все чекбоксы
        navControls.setIsChecked(false);
        navMobs.setIsChecked(false);
        navTheme.setIsChecked(false);
        navAnim.setIsChecked(false);
        navLog.setIsChecked(false);

        switch (page) {
            case "Controls" -> { pageControls.setVisibility(NSGui_Visibility.Visible); navControls.setIsChecked(true); titleRight.setText("Controls"); }
            case "Mobs"     -> { pageMobs.setVisibility(NSGui_Visibility.Visible);     navMobs.setIsChecked(true);     titleRight.setText("Mob Tiles"); }
            case "Theme"    -> { pageTheme.setVisibility(NSGui_Visibility.Visible);    navTheme.setIsChecked(true);    titleRight.setText("Themes"); }
            case "Anim"     -> { pageAnim.setVisibility(NSGui_Visibility.Visible);     navAnim.setIsChecked(true);     titleRight.setText("Animations"); }
            case "Log"      -> { pageLog.setVisibility(NSGui_Visibility.Visible);      navLog.setIsChecked(true);      titleRight.setText("Log"); }
        }

        navGuard = false;
    }

    private void fillMobsExample() {
//        mobWrap.getChildren().clear();

        String[] mobs = { "minecraft:zombie", "minecraft:skeleton", "minecraft:creeper", "minecraft:enderman" };

        for (String id : mobs) {
            var btn = new NSButton();
            btn.setMargin(new NSThickness(6,6,6,6));
            btn.setPadding(new NSThickness(8,8,8,8));

            var sp = new NSStackPanel();
            var name = new NSTextBlock(); name.setText(id);
            name.setTextAlignment(NSGui_TextAlignment.TextAlignment_Center);
            sp.getChildren().add(name);

            btn.setContent(sp);

            btn.clickEvent((c,a) -> {
                setLast("Spawn: " + id);
                System.out.println("TODO spawn: " + id);
            });

            mobWrap.getChildren().add(btn);
        }

        mobCount.setText(mobs.length + " mobs");
    }
}
