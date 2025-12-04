import dev.sixik.noesisgui.NoesisGui;
import dev.sixik.noesisgui.nscore.NSInterface;
import dev.sixik.noesisgui.nscore.NSSymbol;
import dev.sixik.noesisgui.nscore.NSType;
import dev.sixik.noesisgui.nsgui.NSIRenderer;
import dev.sixik.noesisgui.nsgui.NSVisual;
import dev.sixik.noesisgui.nsdrawing.NSColor;
import dev.sixik.noesisgui.nsdrawing.NSCornerRadius;
import dev.sixik.noesisgui_ini.NoesisGuiJava;

public class NoesisTest {

    public static void main(String[] args) {
        NoesisGuiJava.Initialize();

        start("NSColor");
        NSColor color = new NSColor();
        color.setScR(0.1f);
        color.setScG(0.2f);
        color.setScB(5);
        color.setScA(0);

        System.out.println(color.getScR());
        System.out.println(color.getScG());
        System.out.println(color.getScB());
        System.out.println(color.getScA());

        int b = color.getPackedBGRA();
        int f = color.getPackedRGBA();

        System.out.println(NSColor.fromPackedBGRA(b));
        System.out.println(NSColor.fromPackedRGBA(f));

        color.setA(5f);
        color.setB(3f);
        color.setG(1.5f);
        color.setR(2.1f);

        b = color.getPackedBGRA();
        f = color.getPackedRGBA();

        System.out.println(color.a);
        System.out.println(color.b);
        System.out.println(color.g);
        System.out.println(color.r);

        System.out.println(NSColor.fromPackedBGRA(b));
        System.out.println(NSColor.fromPackedRGBA(f));

        space();
        start("NSCornerRadius");
        try (NSCornerRadius radius = new NSCornerRadius(50)) {
            System.out.println(radius.getBottomLeft());
            System.out.println(radius.getBottomRight());
            System.out.println(radius.getTopLeft());
            System.out.println(radius.getTopRight());

            radius.setBottomLeft(0.5f);
            radius.setBottomRight(82);
            radius.setTopLeft(32);
            radius.setTopRight(35);

            System.out.println(radius.getBottomLeft());
            System.out.println(radius.getBottomRight());
            System.out.println(radius.getTopLeft());
            System.out.println(radius.getTopRight());
        }
        space();
        start("NSSymbol");
        try(NSSymbol symbol = new NSSymbol(20)) {
            System.out.println(symbol.getPtr());
            System.out.println(symbol.isNull());
        }
        end();

        start("NSType");
        try(NSType type = new NSType("fobos")) {
            System.out.println(type.getTypeId());
        }
        end();
        space();
        start("NsVisual");

        NSIRenderer renderer = new NSIRenderer(1);
        renderer.render();

//        NSVisual visual = new NSVisual(1);
//        visual.getView();

//        NoesisGui.parseXaml("someCod").


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
