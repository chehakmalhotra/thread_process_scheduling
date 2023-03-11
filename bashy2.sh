start=$(date +"%s.%N")

cd linux2-5.19.8
make -j$(nproc)
cd ..

#sleep 5
end=$(date +"%s.%N")

echo -n "2: "
echo "($end-$start)" | bc -l

echo -n "2: " >> mata.txt
echo "($end-$start)" | bc -l >> mata.txt