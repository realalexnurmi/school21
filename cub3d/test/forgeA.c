float start = round(line.p1.y);
float end = line.p1.x + grad*(start - line.p1.y);
float gap = rfpart(line.p1.y + 0.5);
int ypxl1 = start;
int xpxl1 = ipart(end);
plot(data, get_pxl(get_point(xpxl1, ypxl1), clr), rfpart(end)*gap);
plot(data, get_pxl(get_point(xpxl1 + 1, ypxl1), clr), fpart(end)*gap);
float inter = end + grad;
start = round(line.p2.y);
end = line.p2.x + grad*(start - line.p2.y);
gap = fpart(line.p2.y+0.5);
int ypxl2 = start;
int xpxl2 = ipart(end);
plot(data, get_pxl(get_point(xpxl2, ypxl2), clr), rfpart(end) * gap);
plot(data, get_pxl(get_point(xpxl2 + 1, ypxl2), clr), fpart(end) * gap);
int a;
for(a=ypxl1+1; a < ypxl2; y++)
{
	plot(data, get_pxl(get_point(ipart(inter), a), clr), rfpart(inter));
    plot(data, get_pxl(get_point(ipart(inter) + 1, a), clr), fpart(inter));
    inter += grad;
}