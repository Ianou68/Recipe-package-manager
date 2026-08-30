echo "Installation de fastfetch..."

git clone https://github.com/fastfetch-cli/fastfetch.git /tmp/fastfetch --depth=1

mkdir -p /tmp/fastfetch/build
cd /tmp/fastfetch/build

cmake .. -DENABLE_VULKAN=OFF
cmake --build .
sudo cmake --install .

cd -
rm -rf /tmp/fastfetch
