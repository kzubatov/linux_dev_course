set pagination off

set $s=0
b range_get
commands
  set $s=$s+1
  if $s >= 28 && $s <= 35
    printf "@@@%d %d %d %d\n", r->start, r->stop, r->step, r->i
  end
  continue
end

run -100 100 3 > /dev/null 
quit
