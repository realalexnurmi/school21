float start = round(line.p1.x);
float end = line.p1.y + grad*(start - line.p1.x);
float gap = rfpart(line.p1.x + 0.5);
int xpxl1 = start;
int ypxl1 = ipart(end);
plot(data, get_pxl(get_point(xpxl1, ypxl1), clr), rfpart(end)*gap);
plot(data, get_pxl(get_point(xpxl1, ypxl1+1), clr), fpart(end)*gap);
float inter = end + grad;
start = round(line.p2.x);
end = line.p2.y + grad*(start - line.p2.x);
gap = fpart(line.p2.x+0.5);
int xpxl2 = start;
int ypxl2 = ipart(end);
plot(data, get_pxl(get_point(xpxl2, ypxl2), clr), rfpart(end) * gap);
plot(data, get_pxl(get_point(xpxl2, ypxl2 + 1), clr), fpart(end) * gap);
int a;
for (a=xpxl1+1; a < xpxl2; a++) 
{
	plot(data, get_pxl(get_point(a, ipart(inter)), clr), rfpart(inter));
	plot(data, get_pxl(get_point(a, ipart(inter) + 1), clr), fpart(inter));
	inter += grad;
}

void quickSort(int *numbers, int left, int right)
{
  int pivot; // разрешающий элемент
  int l_hold = left; //левая граница
  int r_hold = right; // правая граница
  pivot = numbers[left];
  while (left < right) // пока границы не сомкнутся
  {
    while ((numbers[right] >= pivot) && (left < right))
      right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
    if (left != right) // если границы не сомкнулись
    {
      numbers[left] = numbers[right]; // перемещаем элемент [right] на место разрешающего
      left++; // сдвигаем левую границу вправо
    }
    while ((numbers[left] <= pivot) && (left < right))
      left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
    if (left != right) // если границы не сомкнулись
    {
      numbers[right] = numbers[left]; // перемещаем элемент [left] на место [right]
      right--; // сдвигаем правую границу вправо
    }
  }
  numbers[left] = pivot; // ставим разрешающий элемент на место
  pivot = left;
  left = l_hold;
  right = r_hold;
  if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
    quickSort(numbers, left, pivot - 1);
  if (right > pivot)
    quickSort(numbers, pivot + 1, right);
}