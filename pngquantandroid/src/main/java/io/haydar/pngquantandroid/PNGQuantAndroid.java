package io.haydar.pngquantandroid;

/**
 * Created by gjy on 2017/11/10.
 */

public class PNGQuantAndroid {
    static {
        System.loadLibrary("pngquantandroid");
    }

    public native boolean compressImage(String inputPath, String outputPath);

}
