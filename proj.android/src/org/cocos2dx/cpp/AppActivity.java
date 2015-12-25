/****************************************************************************
Copyright (c) 2008-2010 Ricardo Quesada
Copyright (c) 2010-2012 cocos2d-x.org
Copyright (c) 2011      Zynga Inc.
Copyright (c) 2013-2014 Chukong Technologies Inc.
 
http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
package org.cocos2dx.cpp;

import org.cocos2dx.lib.Cocos2dxActivity;

import com.tendcloud.tenddata.TalkingDataGA;

import android.os.Bundle;
import android.graphics.Color;
import android.view.Gravity;
import android.view.ViewGroup.LayoutParams;
import android.view.WindowManager;
import android.widget.FrameLayout;

import com.google.android.gms.ads.AdRequest;
import com.google.android.gms.ads.AdSize;
import com.google.android.gms.ads.AdView;


public class AppActivity extends Cocos2dxActivity {
	private AdView adView;
	private static final String AD_UNIT_ID = "ca-app-pub-5009665577000890/9760595766";
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		TalkingDataGA.sPlatformType=TalkingDataGA.PLATFORM_TYPE_COCOS2DX;
		TalkingDataGA.init(this.getApplicationContext(), "400D7D1065BEABD0019F98038AD98627", "TalkingData");

		getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
		adView = new AdView(this);
		adView.setAdSize(AdSize.BANNER);
		adView.setAdUnitId(AD_UNIT_ID);

		AdRequest adRequest = new AdRequest.Builder()
				.addTestDevice(AdRequest.DEVICE_ID_EMULATOR)
				.addTestDevice("1DF047946C45C68B7DBD7BB4027CC800").build();

		adView.loadAd(adRequest);
		adView.setBackgroundColor(Color.BLACK);
		adView.setBackgroundColor(0);

		FrameLayout.LayoutParams params = new FrameLayout.LayoutParams(
				LayoutParams.WRAP_CONTENT, LayoutParams.WRAP_CONTENT);
		params.gravity = Gravity.TOP;

		addContentView(adView, params);
	}
	
	@Override
	protected void onPause() {
		super.onPause();
		TalkingDataGA.onPause(this);
		if (adView != null) {
			adView.pause();
		}
	}
	
	@Override
	protected void onResume() {
		super.onResume();
		TalkingDataGA.onResume(this);
		if (adView != null) {
			adView.resume();
		}
	}

	@Override
	protected void onDestroy() {
		super.onDestroy();
		adView.destroy();
	}
}