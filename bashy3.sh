start=$(date +"%s.%N")

cd linux3-5.19.8
make -j$(nproc)
cd ..

# sleep 2
end=$(date +"%s.%N")

echo -n "3: "
echo "($end-$start)" | bc -l

echo -n "3: " >> mata.txt
echo "($end-$start)" | bc -l >> mata.txt