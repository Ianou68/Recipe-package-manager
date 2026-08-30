#include <stdio.h>
#include <stdlib.h>
#include <string.h>

  void install() {
    const char *url = "https://github.com/fastfetch-cli/fastfetch/releases/download/2.67.0/fastfetch-linux-amd64.tar.gz";

    printf("Récupération du tar.gz\n");
  
    char commande[512];

    snprintf(commande, sizeof(commande), "curl -sL \"%s\" -o /tmp/fastfetch.tar.gz", url);

    system(commande);

    printf("install");
    system("mkdir -p ~/.local/bin");
    system("tar -xzf /tmp/fastfetch.tar.gz -C ~/.local/bin --strip-components=3 fastfetch-linux-amd64/usr/bin/fastfetch");

    system("rm -rf /tmp/fastfetch.tar.gz");

    printf("C'est terminé");
  }
  void supprimer() {
    printf("suprimation ...");
    system("rm -rf ~/.local/bin/fastfetch");
  }
  int main(int argc, char *argv[]) {
    // Vérifie si un argument est passé (ex: ./my_pm install)
    if (argc < 2) {
        printf("Usage: %s {install|remove}\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "install") == 0) {
        install();
    } else if (strcmp(argv[1], "remove") == 0) {
        supprimer();
    } else {
        printf("Commande inconnue : %s\n", argv[1]);
        printf("Usage: %s {install|remove}\n", argv[0]);
        return 1;
    }

    return 0;
} 
