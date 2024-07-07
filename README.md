# helmet_rgb_breath_led
安全帽呼吸燈

之前在安全帽上黏的黃色小鴨，如果在夜晚可以發出光芒就太美好了
<hr>
<img src="snapshot/s1.jpg">
<br>
<img src="snapshot/s2.jpg">
<br>

關聯套件：
	1. SystemStatus 可以用來讀出 Attiny VCC 電壓，且不用增加任何電路
	2. TinyWireM、Tiny4kOLED 提供 OLED 顯示文字使用
	3. Adafruit_NeoPixel 提供 W2812B Pixel LED 使用

注意事項：
ATTiny85 使用 8mHZ 編譯

<img src="snapshot/helmet_rgb_breath_led_devel.png">
開發模式：偵測 14500 鋰電池剩餘電量，使用 OLED 128x64 液晶面板
將抓到的電池電壓顯示

<img src="snapshot/helmet_rgb_breath_led_release.png">
發行模式：安裝二排 W2812B Pixel LED，可以共用同一組 DI 線


Reference:
	1. https://github.com/cano64/ArduinoSystemStatus
	2. https://github.com/adafruit/TinyWireM
	3. https://github.com/datacute/Tiny4kOLED
	4. https://github.com/adafruit/Adafruit_NeoPixel
