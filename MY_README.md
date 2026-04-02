make -j12 TARGET=SITL EXTRA_FLAGS="-DUSE_ALTITUDE_HOLD -DUSE_POSITION_HOLD -DUSE_GPS"

./obj/main/betaflight_SITL.elf 172.27.128.1 --uart port=/tmp/betaflight_sitl_udp,speed=115200