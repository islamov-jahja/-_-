package mainProgram;

import java.util.ArrayList;
import java.util.List;
import java.io.FileWriter;
import java.io.IOException;
import org.jsoup.Jsoup;
import java.net.*;
import org.jsoup.nodes.Document;
import org.jsoup.select.Elements;


public class ProgramMain {
    public static void main(String[] args) throws IOException {
        String url = "http://links.testingcourse.ru";
        List<String> linkhref = new ArrayList<>();
        List<String> linkhrefForCheck = new ArrayList<>();
        linkhref.add(url);
        FileWriter brokenLinksF = new FileWriter("brokenLinks.txt", false);
        FileWriter normalLinksF = new FileWriter("normalLinks.txt", false);
        String domen = getDomen(url);
        URL urlForConnection = null;
        HttpURLConnection connection;
        int statusCode;

        int i = 0;
        while ((linkhref.size() - i) >= 1) {
            url = linkhref.get(i);
            try {
                urlForConnection = new URL(url);
                connection = (HttpURLConnection) urlForConnection.openConnection();
                connection.setRequestMethod("GET");
                statusCode = connection.getResponseCode();

                if (statusCode >= 400)
                    brokenLinksF.write(url + " " + statusCode + '\n');
                else
                    normalLinksF.write(url + " " + statusCode + '\n');

                if (i == 0 || (url.contains(domen))) {
                    Document doc = Jsoup.connect(url).get();
                    Elements links = doc.select("a[href]"); // a with href
                    linkhrefForCheck.addAll(links.eachAttr("abs:href"));
                    AddingUniqueLinks(linkhref, linkhrefForCheck);
                }

                i++;
            }catch (Exception e) {
                i++;
                continue;
            }
        }

        brokenLinksF.close();
        normalLinksF.close();
    }

    static void AddingUniqueLinks(List<String> arr1, List<String> arr2){
        for (int i = 0; i < arr2.size(); i++){
            if (arr1.contains(arr2.get(i)))
                continue;
            else
                arr1.add(arr2.get(i));
        }
    }

    static boolean IsUiquenessDomen(String domen1, String domen2){
        if (domen1 == domen2)
            return true;
        else
            return false;
    }

    static String getDomen(String url){
        int startIndex = 0;
        if (url.indexOf("http") != -1)
            startIndex = 8;
        else
            startIndex = 9;

        int index = url.lastIndexOf('.');
        for (int i = startIndex; i < index; i++){
            if (url.charAt(i) == '/') {
                index = i;
                break;
            }
        }
        String substr = url.substring(0,index);
        return substr;
    }
}
