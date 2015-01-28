# S2_IHM

http://mrim.imag.fr/GINF53C4/PROJET/

### Compilation :

cc rdjpeg.c read_image.c -o read_image

### Execution sur une image :

./read_image  http://mrim.imag.fr/voc10/images/2008_000015.jpg

### Génération fichier train.libsvm.txt et val.libsvm.txt :

./script_gen_histo data/val/urls.txt > data/val/svm/color.svm

./script_gen_histo data/train/urls.txt > data/train/svm/color.svm

### Génération d'une fusion d'histogramme et d'annotations pour un concept :

./script_fusion_histo_ann data/train/svm/color.svm data/train/ann/aeroplane.ann > data/train/svm/color_aeroplan.svm

### Génération d'un model pour un concept :

./script_gen_model color_aeroplane

### Génération de tous les models pour tous les concepts :

./script_gen_models

### Génération de tous les predics pour tous les concepts :

./script_gen_predicts
