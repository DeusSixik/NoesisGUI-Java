import dev.sixik.noesisgui.nsapp.NsNotifyPropertyChangedBase;
import dev.sixik.noesisgui.nscore.NSBaseComponent;
import dev.sixik.noesisgui.nsgui.NSPropertyChangedEventArgs;

public class MyTestViewModel extends NsNotifyPropertyChangedBase {

    public MyTestViewModel() {
        propertyChangedEvent(this::event);
    }

    private void event(NSBaseComponent component, NSPropertyChangedEventArgs nsPropertyChangedEventArgs) {
        System.out.println(nsPropertyChangedEventArgs.symbol);
    }
}
