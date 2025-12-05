import dev.sixik.noesisgui.NoesisGui;
import dev.sixik.noesisgui.nsgui.NSUIElement;
import dev.sixik.noesisgui_ini.NoesisGuiJava;
import dev.sixik.noesisgui_render.gl.NSOpenGl;

public class NoesisTest {

    public static void main(String[] args) {
        NoesisGuiJava.Initialize();

        NoesisGui.init();

        NSOpenGl.createDevice(false);

        NSUIElement data = NoesisGui.parseXaml("""
                <Grid xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation">
                          <Grid.Background>
                            <LinearGradientBrush StartPoint="0,0" EndPoint="0,1">
                              <GradientStop Offset="0" Color="#FF123F61"/>
                              <GradientStop Offset="0.6" Color="#FF0E4B79"/>
                              <GradientStop Offset="0.7" Color="#FF106097"/>
                            </LinearGradientBrush>
                          </Grid.Background>
                          <Viewbox>
                            <StackPanel Margin="50">
                              <Button Content="Hello World!" Margin="0,30,0,0"/>
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

        System.out.println(data.getPtr());
        data.destroy();
    }

    private static void start(String name) {
        System.out.println("------" + name + "------");
    }

    private static void end() {
        System.out.println("------------");
    }

    private static void space() {
        space(1);
    }

    private static void space(int space) {
        for (int i = 0; i < space; i++) {
            System.out.println("\n");
        }
    }
}
