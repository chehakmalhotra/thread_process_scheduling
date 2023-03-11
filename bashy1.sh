start=$(date +"%s.%N")
cd linux1-5.19.8
make -j$(nproc)
cd ..

#sleep 1
end=$(date +"%s.%N")

echo -n "1: "
echo "($end-$start)" | bc -l
echo -n "1: " >> mata.txt
echo "($end-$start)" | bc -l >> mata.txt