package com.example.matlabfcn_whistlecount;

import android.test.ActivityInstrumentationTestCase2;

/**
 * This is a simple framework for a test of an Application.  See
 * {@link android.test.ApplicationTestCase ApplicationTestCase} for more information on
 * how to write and extend Application tests.
 * <p/>
 * To run this test, you can type:
 * adb shell am instrument -w \
 * -e class com.example.matlabfcn_whistlecount.matlabfcn_whistlecountTest \
 * com.example.matlabfcn_whistlecount.tests/android.test.InstrumentationTestRunner
 */
public class matlabfcn_whistlecountTest extends ActivityInstrumentationTestCase2<matlabfcn_whistlecount> {

    public matlabfcn_whistlecountTest() {
        super("com.example.matlabfcn_whistlecount", matlabfcn_whistlecount.class);
    }

}
