## Builtins

| Nom           | Description            | Supporté ?  | Bonus ?  |
| ------------- |:----------------      | -----:| -----:|
|Cd       | Changer le répertoir de travail | ✓ | ✗ |
|Clear    | Effacer tout ce qui est sur le terminal          |   ✓ | ✓ |
|Echo     | Afficher les arguments dans le terminal  | ✓ | ✗ |
|Env      | Afficher les variables d'environements  | ✓ | ✗ |
|Setenv   | Modifier ou créer des variables d'environements  | ✓ | ✗ |
|Unsetenv | Supprimer une ou plusieurs variables d'environements  | ✓ | ✗ |
|Exit     | Quitter le terminal et libérer la memoire | ✓ | ✗ |
|Pwd      | Affiche le répertoire courrant | ✓ | ✓ |
|Searchbin| Affiche le répertoire courrant | ✓ | ✓ |
|History  | Affiche au complet l'historique des commandes | ✓ | ✓ |
|!!       | Met la dernière commande dans le prompt | ✓ | ✓ |
|!n       | Met la n-ième command en partant du début de l'historique dans le pompt| ✓ | ✓ |
|!-n      | Met la n-ième command en partant du début de la fin dans le prompt| ✓ | ✓ |
|!?name   | Met la première command qui contient name dans le prompt | ✓ | ✓ |
|!name    | Met la première command qui commence par name dans le prompt | ✓ | ✓ |
|calc     | Affiche un prompt pour calculer des expressions à la manière de bc | ✓ | ✓ |

## Edition de la ligne de commande

| Nom                            | Description                         | Supporté ?  | Bonus ?  |
| -------------                  |:----------------                    | -----:| -----:|
| <kbd>CTRL</kbd>+<kbd>T</kbd>   | Échange la position des charactères | ✓ | ✓ |
| <kbd>CTRL</kbd>+<kbd>U</kbd>   | Supprime toute la ligne             | ✓ | ✗ |
| <kbd>CTRL</kbd>+<kbd>K</kbd>   | Supprime du curseur à la fin de la ligne | ✓ | ✗ |
| <kbd>CTRL</kbd>+<kbd>A</kbd>   | Positionne le curseur au debut de la ligne | ✓ | ✗ |
| <kbd>CTRL</kbd>+<kbd>E</kbd>   | Positionne le curseur à la fin de la ligne | ✓ | ✗ |
| <kbd>CTRL</kbd>+<kbd>W</kbd>   | Supprime le dernier mot | ✓ | ✓ |
| <kbd>CTRL</kbd>+<kbd>L</kbd>   | Effacer tout ce qui est sur le terminal | ✓ | ✓ |
| <kbd>CTRL</kbd>+<kbd>B</kbd>   | Curseur à gauche | ✓ | ✗ |
| <kbd>CTRL</kbd>+<kbd>F</kbd>   | Curseur à droite | ✓ | ✗ |
| <kbd>CTRL</kbd>+<kbd>I</kbd>   | Descend le curseur d'une ligne quand multi-ligne | ✓ | ✗ |
| <kbd>CTRL</kbd>+<kbd>O</kbd>   | Monte le curseur d'une ligne quand multi-ligne | ✓ | ✗ |
| <kbd>CTRL</kbd>+<kbd>H</kbd>   | Affiche un prompt pour rechercher dans l'historique | ✓ | ✓ |
| <kbd>delete</kbd>              | Supprime le caractère à droite | ✓ | ✓ |
| <kbd>home</kbd>                | Positionne le curseur au debut de la ligne | ✓ | ✗ |
| <kbd>end</kbd>                 | Positionne le curseur à la fin de la ligne | ✓ | ✗ |
| <kbd>backspace</kbd>           | Supprime le caractère vers la gauche| ✓ | ✗ |
| <kbd>SHIFT</kbd> + <kbd>▲</kbd>| Monte le curseur d'une ligne quand multi-ligne | ✓ | ✗ |
| <kbd>tab</kbd>                 | Affiche la complétion | ✓ | ✓ |
| <kbd>SHIFT</kbd> + <kbd>▼</kbd>| Descend le curseur d'une ligne quand multi-ligne | ✓ | ✗ |
| <kbd>SHIFT</kbd> + <kbd>▶</kbd>| Position le curseur au prochain debut de mot | ✓ | ✗ |
| <kbd>SHIFT</kbd> + <kbd>◀</kbd>| Position le curseur au prochain debut de mot | ✓ | ✗ |
| <kbd>◀</kbd>                   | Position le curseur à gauche | ✓ | ✗ |
| <kbd>▶</kbd>                   | Position le curseur à droite | ✓ | ✗ |
| <kbd>▲</kbd>                   | Affiche le prochain historique le plus vieux | ✓ | ✗ |
| <kbd>▼</kbd>                   | Affiche le prochain historique le plus récent | ✓ | ✗ |

## Éxectution des commandes

| Nom           | Description            | Supporté?  | Bonus  |
| ------------- |:----------------      | -----:| -----:|
| Commande du path | Éxecute une commande depuis le path | ✓ | ✗ |
| Séparateur `;` | Éxecute une commande puis une autre | ✓ | ✓ |
| Séparateur  | Éxecute une commande OU une autre en fonction de si l'execution m'a pas été reussi ou pas | ✓ | ✓ |
| Séparateur <code>&&#124;</code> | Éxecute une commande puis une autre | ✓ | ✓ |
| Séparateur `&&` | Éxecute une commande ET une autre en fonction de si l'execution à été reussi| ✓ | ✓ |
| Opérateur `>` | Redirige la sortie standard vers un autre file descriptor| ✓ | ✓ |
| Opérateur `>>` | Redirige la sortie standard vers un autre file descriptor (ajout à la fin)| ✓ | ✓ |
| Opérateur `<<` | Heredoc |  ✓ | ✓ |
| Opérateur `<` | Redirige l'entrée standard vers la commande| ✓ | ✓ |
| Pipe <code>&#124;</code>| le fameux pipe (ex ls <code>&#124;</code> frep 21sh)| ✓ | ✓ |
| Echappement des guillements dans les commandes | Exemple: "l"s                | ✓ | ✓ |
| Gestion avancée des erreurs | Exemple: ls ; ;                                 | ✓ | ✓ |
| Gestion du tilde | Exemple: cd ~                                              | ✓ | ✓ |
| Gestion du des variables d'environement | Exemple: echo $PATH                 | ✓ | ✓ |

## Autres bonus


| Nom                                          | Description                                    | Supporté? | Bonus   |
| -------------                                |:----------------                               | -----:    | -----:  |
| Hashtable pour les binaires                  | table de hash pour les binaires                | ✓         | ✓       |
| Hashtable pour les variables d'environements | table de hash pour les variable d'environement | ✓         | ✓       |
| Multi line support                           | >                                              | ✓         | ✓       |
| Dquote                                       | dquote>                                        | ✓         | ✓       |
