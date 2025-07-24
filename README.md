# ros2_simplejoyv2
This is a  simple ros2 jazzy pkg to publish msgs with a bluetooth joystick(only xbox one cotroller is used you have to test with other controllers).
It is meant for linux sbc computer like Raspberry Pi and ubuntu desktop pc/laptop. It has a 1 publisher node that publish msgs with joystick buttons and 2 subscriber node(one simple member subscriber and 1 subscriber nodes that toggles led depending on msg data received).
If you wanna use this nodes links below can help:

to pair the joystick with bluetooth :https://pimylifeup.com/raspberry-pi-bluetooth/,

to install the gpio library: https://github.com/WiringPi/WiringPi.git
