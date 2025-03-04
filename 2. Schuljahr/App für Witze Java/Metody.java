import com.google.gson.Gson;
import com.google.gson.JsonObject;
import java.io.*;
import java.net.HttpURLConnection;
import java.net.URL;

public class Metody {
    Metody() {
    }

    public void ukladam() {
        try (FileWriter writer = new FileWriter("mojaURL.json")) {
            String urlToRead = ("https://api.chucknorris.io/jokes/random");
            StringBuilder result = new StringBuilder();
            URL url = new URL(urlToRead);
            HttpURLConnection conn = (HttpURLConnection) url.openConnection();
            conn.setRequestMethod("GET");
            try (BufferedReader reader = new BufferedReader(
                    new InputStreamReader(conn.getInputStream()))) {
                for (String line; (line = reader.readLine()) != null; ) {
                    result.append(line);
                }
                writer.write(result.toString());
//                System.out.println(result);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public String nacitavam() {
        try (Reader reader = new FileReader("mojaURL.json")) {
            JsonObject jobj = new Gson().fromJson(reader, JsonObject.class);
            String vtip = jobj.get("value").getAsString();
            String malina = vtip;
            System.out.println("Vtip znie takto : " + vtip);
        } catch (IOException exception) {
            exception.printStackTrace();
        }
        return "";
    }
}
