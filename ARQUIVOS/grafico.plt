set terminal png
set border linewidth 1.5
set output 'grafico.png'
set title "Algoritmos de Ordenação"
set xlabel "Número de pontos"
set logscale y

plot "tempos.txt" u 1:3 w lines lc "purple" lw 3 title "Selection Sort"
plot "tempos.txt" u 1:2 w lines lc "blue" title "Bubble Sort"
plot "tempos.txt" u 1:4 w lines lc "red" lw 2 title "Quick Sort"
plot "tempos.txt" u 1:3 w lines lc "yellow" lw 3 title "Merge Sort"
plot "tempos.txt" u 1:2 w lines lc "orange" title "Bucket Sort"
plot "tempos.txt" u 1:4 w lines lc "black" lw 2 title "Gnome Sort"
plot "tempos.txt" u 1:4 w lines lc "gray" lw 2 title "Shell Sort"
