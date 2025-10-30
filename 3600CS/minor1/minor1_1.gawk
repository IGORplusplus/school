NR > 1 {
angle = $1
while(angle < 0) 
{ angle += 360 }
while(angle > 360) 
{ angle -= 360 }
{printf "%8d %d\n", $1, angle}
}
