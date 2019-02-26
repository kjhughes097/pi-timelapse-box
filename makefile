all:
	gcc *.cpp -o timelapse-box -lstdc++ -std=c++11

clean:
	rm -f timelapse-box

