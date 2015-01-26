# S2_IHM

http://mrim.imag.fr/GINF53C4/PROJET/

### Compilation :

cc rdjpeg.c read_image.c -o read_image

### Execution sur une image :

./read_image  http://mrim.imag.fr/voc10/images/2008_000015.jpg

### Génération fichier train.libsvm.txt et val.libsvm.txt :

./script_gen_histo val.urls.txt > val.libsvm.txt

./script_gen_histo train.urls.txt > train.libsvm.txt
