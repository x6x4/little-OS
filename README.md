Some experiments in writing an C-assembly OS \

od -t o1 driver | awk '{$1=""; print $0}' | ./a.out
