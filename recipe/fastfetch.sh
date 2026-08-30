echo installation de fastfetch

git clone https://github.com/fastfetch-cli/fastfetch.git /tmp/fastfetch --depth=1

mkdir -p /tmp/fastfetch/build

cd /tmp/fastfetch/build

cmake ..
cmake --build . --target fastfetch
sudo cmake --install .

cd -

rm -rf /tmp/fastfetch
