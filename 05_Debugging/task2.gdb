set pagination off

set $s=0
b 43
commands
  set $s=$s+1
  if $s >= 28 && $s <= 35
    printf "@@@%d %d %d %d\n", start, stop, step, i
  end
  continue
end

run -100 100 3 > /dev/null 
quit
