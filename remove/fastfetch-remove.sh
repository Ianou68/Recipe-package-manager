#!/usr/bin/env bash

VERSION="2.67.1"
INDEX="/var/udf/index.txt"

echo "Désinstallation de fastfetch..."

# Si installé via CMake / make install
if [ -f /usr/local/bin/fastfetch ]; then
    sudo rm -f /usr/local/bin/fastfetch
fi

if [ -f /usr/bin/fastfetch ]; then
    sudo rm -f /usr/bin/fastfetch
fi

# Supprime aussi flashfetch s'il a été installé
sudo rm -f /usr/local/bin/flashfetch /usr/bin/flashfetch

echo "fastfetch a été désinstallé avec succès."

sed -i '/^fastfetch |/d' "$INDEX"
