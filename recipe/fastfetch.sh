VERSION="2.67.1"
INDEX="/var/udf/index.txt"

if grep -q "^fastfetch |" "$INDEX"; then
    sed -i "s/^fastfetch | .*/fastfetch | $VERSION/" "$INDEX"
else
    echo "fastfetch | $VERSION" >> "$INDEX"
fi

echo "Installation de fastfetch..."

git clone https://github.com/fastfetch-cli/fastfetch.git /tmp/fastfetch --depth=1

mkdir -p /tmp/fastfetch/build
cd /tmp/fastfetch/build

cmake .. -DENABLE_VULKAN=OFF
cmake --build .
sudo cmake --install .

cd -
rm -rf /tmp/fastfetch
