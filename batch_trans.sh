#!/bin/sh
runpath=`pwd`
cd $runpath

echo "remove Config Result"
rm -rf ./Result ./Config

#trans
for f in `cat ./xlsx/list.txt`
do
    filename=${runpath}/xlsx/$f
    echo "handle : $filename ...."
    echo 'csharp reader'
    python ${runpath}/cs_reader.py $filename
    echo "java reader"
    python ${runpath}/java_reader.py $filename
done

echo "csharp manager"
python cs_mgr_gen.py

echo "java manager"
python java_mgr_gen.py

echo "copy csharp CSVReader"
cp ./CSVReader_cs/CSVReader.cs ./Result/cs/CSVReader.cs

echo "copy java CSVReader"
cp ./CSVReader_Java/com/xlsxtools/CSVReader.java ./Result/java/com/xlsxtools/CSVReader.java