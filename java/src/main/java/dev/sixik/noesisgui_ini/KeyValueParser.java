package dev.sixik.noesisgui_ini;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.HashMap;
import java.util.Map;

public class KeyValueParser {

    public static Map<String, String> parseFile(String filePath) throws IOException {
        Map<String, String> result = new HashMap<>();
        Path path = Paths.get(filePath);

        if (!Files.exists(path)) {
            throw new IOException("File not found: " + filePath);
        }

        for (String line : Files.readAllLines(path)) {
            processLine(line, result);
        }

        return result;
    }

    private static void processLine(String line, Map<String, String> map) {
        line = line.trim();

        if (line.isEmpty() || line.startsWith("#") || line.startsWith("//")) {
            return;
        }

        int equalsIndex = line.indexOf('=');
        if (equalsIndex <= 0) {
            System.err.println("Uncorrected line: " + line);
            return;
        }

        String key = line.substring(0, equalsIndex).trim();
        String value = line.substring(equalsIndex + 1).trim();

        if ((value.startsWith("\"") && value.endsWith("\"")) ||
                (value.startsWith("'") && value.endsWith("'"))) {
            value = value.substring(1, value.length() - 1);
        }

        map.put(key, value);
    }
}