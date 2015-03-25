# S2_IHM

http://mrim.imag.fr/GINF53C4/PROJET/

### Compilation :

cc rdjpeg.c read_image.c -o read_image

### Execution sur une image :

./read_image  http://mrim.imag.fr/voc10/images/2008_000015.jpg

### Génération fichier train.libsvm.txt et val.libsvm.txt :

./script_gen_histo data/val/urls.txt > data/val/svm/color.svm

./script_gen_histo data/train/urls.txt > data/train/svm/color.svm

### Génération d'une fusion histogramme/annotations pour un concept :

./script_fusion_histo_ann data/train/svm/color.svm data/train/ann/aeroplane.ann > data/train/svm/color_aeroplan.svm

### Génération d'un model pour un concept :

./script_gen_model color_aeroplane

### Génération de tous les models pour tous les concepts :

./script_gen_models

### Génération de tous les predics pour tous les concepts :

./script_gen_predicts

### Génération d'un .top

./script_gen_top data/val/ann/aeroplane.ann data/val/out/color_aeroplane.out > data/val/top/color_aeroplane.top

### Génération de tous les .top :

./script_gen_tops

### Génération du all.top :

cat data/val/top/* > data/val/top/color_all.top

### Évaluation :

./script_trac_eval > data/val/eval.txt

### Nettoyage SIFT d'1 fichier : 

./script_clean_sift 2008_000019.sift

### Nettoyage SIFT de tous les fichiers :

./script_clean_all_sift

### Création du fichier samples.txt

cat data/train/sift/* > samples.txt

### Génération de centers256.txt avec kmeans_clustering.R

R --slave --no-save --no-restore --no-environ --args ./samples.txt 256 ./centers256.txt 10 < libsvm/kmeans_clustering.R

### Mapping de train

./libsvm/process_1nn_sift.sh

### Mapping de val

./libsvm/process_1nn_sift_val.sh

### Génération des histogrammes de SIFT

./script_gen_histo_sift

### Génération des fichiers val/sift.svm et train/sift.svm

./script_gen_sift_svm

cat data/train/histo_sift_svm/* > data/train/histo_sift_svm/sift.svm

cat data/val/histo_sift_svm/* > data/val/histo_sift_svm/sift.svm

### Génération des models pour sift et des predicts

./script_gen_models_sift

./script_gen_predicts_sift
