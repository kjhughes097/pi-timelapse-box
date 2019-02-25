all:
	gcc timelapse-box.cpp CTimelapseApp.cpp CStatusVersion.cpp ssd1306.cpp -o timelapse-box -std=c++11

clean:
	rm -f timelapse-box

