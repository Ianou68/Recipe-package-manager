#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void install(const char *paquet) {
    printf("Récupération de %s...\n", paquet);

    char command[512];

    // Téléchargement (-f échoue si 404), exécution puis suppression
    snprintf(command, sizeof(command), 
             "curl -fsSL https://raw.githubusercontent.com/Ianou68/Recipe-package-manager/main/recipe/%s.sh -o /tmp/%s.sh && bash /tmp/%s.sh && rm /tmp/%s.sh", 
             paquet, paquet, paquet, paquet);

    int status = system(command);

    if (status != 0) {
        printf("Erreur : l'installation du paquet '%s' a échoué.\n", paquet);
        snprintf(command, sizeof(command), "rm -f /tmp/%s.sh", paquet);
        system(command);
        return;
    }

}
void remove_package(const char *paquet) {
    printf("Désinstallation de %s...\n", paquet);
    char command[512];
    // Cherche la recette nommé <paquet>-remove.sh
    snprintf(command, sizeof(command),
             "curl -fsSL https://raw.githubusercontent.com/Ianou68/Recipe-package-manager/main/remove/%s-remove.sh -o /tmp/%s-remove.sh && bash /tmp/%s-remove.sh && rm /tmp/%s-remove.sh",
             paquet, paquet, paquet, paquet);

    if (system(command) != 0) {
        printf("Erreur ou recette de désinstallation introuvable pour %s.\n", paquet);
        snprintf(command, sizeof(command), "rm -f /tmp/%s-remove.sh", paquet);
        system(command);
    }
}



int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s install <paquet>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "install") == 0) {
        install(argv[2]);
    } else if (strcmp(argv[1], "remove") == 0 || strcmp(argv[1], "uninstall") == 0) {
        remove_package(argv[2]);
    } else {
        printf("Commande inconnue : %s\n", argv[1]);
        printf("Usage: %s install <paquet>\n", argv[0]);
        return 1;
    }

    return 0;
}
