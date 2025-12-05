package dev.sixik.noesisgui_ini;

import java.io.InputStream;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardCopyOption;

public class NoesisGuiJava {

    private static boolean loaded = false;

    public static boolean IsLoaded() {
        return loaded;
    }

    public static void Initialize() {
        if(loaded) return;

        try {
            // Создаём одну временную папку под все DLL
            Path tempDir = Files.createTempDirectory("noesis_native_");
            tempDir.toFile().deleteOnExit();

            // Список библиотек, как ты их назовёшь / как дают Noesis
            String[] libs = {
                    "Noesis.dll",      // пример, реальные имена подставишь свои
                    "NoesisApp.dll",   // если нужна
                    "noesis_jni.dll"   // наш JNI-слой
            };

            for (String lib : libs) {
                extractLib("/native/win64/" + lib, tempDir.resolve(lib));
            }

            // ВАЖНО: сначала грузим сами Noesis DLL,
            // потом – наш noesis_jni.dll
            System.load(tempDir.resolve("Noesis.dll").toString());
            // если есть ещё зависимости:
             System.load(tempDir.resolve("NoesisApp.dll").toString());

            System.load(tempDir.resolve("noesis_jni.dll").toString());

            loaded = true;
        } catch (Exception e) {
            throw new RuntimeException("Failed to load Noesis native libs", e);
        }
    }

    private static void extractLib(String resourcePath, Path dst) throws Exception {
        try (InputStream in = NoesisGuiJava.class.getResourceAsStream(resourcePath)) {
            if (in == null) {
                throw new RuntimeException("Native resource not found: " + resourcePath);
            }
            Files.copy(in, dst, StandardCopyOption.REPLACE_EXISTING);
            dst.toFile().deleteOnExit();
        }
    }
}
