#!/bin/sh
runpath=`pwd`
cd $runpath

echo -e "remove Config Result\n"
rm -rf ./Result ./Config

for f in `cat ./xlsx/list.txt`
do
    filename=${runpath}/xlsx/$f
    echo "file:$filename"
    echo 'csharp reader'
    python ${runpath}/cs_reader.py $filename
    echo "java reader"
    python ${runpath}/java_reader.py $filename
done

echo -e "\n------csharp manager------"
python cs_mgr_gen.py

echo -e "\n------java manager------"
python java_mgr_gen.py

echo -e "\n------copy csharp CSVReader------"
cp ./CSVReader_cs/CSVReader.cs ./Result/cs/CSVReader.cs

echo -e "\n------copy java CSVReader------"
cp ./CSVReader_Java/com/xlsxtools/CSVReader.java ./Result/java/com/xlsxtools/CSVReader.java