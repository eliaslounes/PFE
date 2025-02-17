apt-get install cmake make gcc g++ pkg-config libfftw3-dev libmbedtls-dev libsctp-dev libyaml-cpp-dev libgtest-dev git curl jq -y
apt-get install libuhd-dev libuhd4.4.0 uhd-host -y
uhd_find_devices
git clone https://github.com/srsran/srsRAN_Project.git
cd srsRAN_Project/
mkdir build
cd build/
cmake ../ -DENABLE_EXPORT=ON -DUHD=ON
make -j`nproc`
make install
ldconfig
cp /root/srsRAN_Project/build/apps/gnb /usr/bin/gnb
