#!/bin/bash

#./scripts/run_openocd.sh &

sleep 5

cd ..
cd objectiveStm32


echo "
target remote localhost:3333
monitor reset halt
load out/objectiveStm32.elf
monitor reset run
quit
" > tmp

arm-none-eabi-gdb out/objectiveStm32.elf -x tmp -q

rm tmp

