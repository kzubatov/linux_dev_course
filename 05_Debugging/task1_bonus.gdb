set pagination off

b range_get if r->i % 5 == 0
  commands
    echo @@@
    printf "%d %d %d %d\n", r->start, r->stop, r->step, r->i
    continue
  end
run 1 12 > /dev/null 
quit
