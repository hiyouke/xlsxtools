#!/bin/sh
runpath=`pwd`
cd $runpath

echo -e "remove Config Result\n"
rm -rf ./Result ./Config

for f in `cat ./xlsx/list.txt`
do
    filename=${runpath}/xlsx/$f

    echo "generate txt"
    echo -e "python $runpath/xlsx_to_txt.py $filename\n------------------\n"
    python $runpath/xlsx_to_txt.py $filename

    echo "generate csharp reader"
    echo -e "python $runpath/cs_reader.py $filename\n------------------\n"
    python $runpath/cs_reader.py $filename

    echo "generate java reader"
    echo -e "python $runpath/java_reader.py $filename\n------------------\n"
    python $runpath/java_reader.py $filename

    echo "cpp reader"
    echo -e "python $runpath/cpp_reader.py $filename\n------------------\n"
    python $runpath/cpp_reader.py $filename
done


echo -e "\n------csharp manager------"
python cs_mgr_gen.py
echo -e "\n------copy csharp CSVReader------"
cp ./CSVReader_cs/CSVReader.cs ./Result/cs/CSVReader.cs


echo -e "\n------java manager------"
python java_mgr_gen.py
echo -e "\n------copy java CSVReader------"
cp ./CSVReader_Java/com/xlsxtools/CSVReader.java ./Result/java/com/xlsxtools/CSVReader.java

echo -e "\n------cpp manager------"
python cpp_mgr_gen.py
echo -e "\n------copy cpp CSVReader------"
cp ./CSVReader_cpp/CSVReader.h ./Result/cpp/CSVReader.h
cp ./CSVReader_cpp/CSVReader.cpp ./Result/cpp/CSVReader.cpp