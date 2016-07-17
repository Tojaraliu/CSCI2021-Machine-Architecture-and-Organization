#!/usr/bin/perl
#!/usr/local/bin/perl

use Getopt::Std;

#
# Configuration
#

$yas = "../sim/misc/yas";
$yis = "../sim/misc/yis";

$goodcnt = 0;

@val = (0,5,1,4);

for ($i = 1; $i <= 4; $i++) {
    
    !(system "cat data$i.txt matrix_and_xor.ys stack.txt> matrix_and_xor_$i.ys") ||     
         die "Couldn't create file matrix_and_xor_$i.ys\n";

    !(system "$yas matrix_and_xor_$i.ys") ||
        die "Couldn't assemble file matrix_and_xor_$i.ys\n";  

    !(system "$yis matrix_and_xor_$i.yo > matrix_and_xor_$i.yis") ||
	die "Couldn't simulate file matrix_and_xor_$i.yo with instruction set simulator\n";

    $stat = `grep rax matrix_and_xor_$i.yis`;
    $stat = substr $stat, 25;
    $stat = hex($stat);  
   
   !(system "rm matrix_and_xor_$i.ys matrix_and_xor_$i.yo matrix_and_xor_$i.yis") ||
       die "Couldn't remove files matrix_and_xor_$i.ys and/or matrix_and_xor_$i.yo and/or matrix_and_xor_$i.yis\n";

    $result = "failed";
    
    if ($stat == $val[$i-1]) {
	$goodcnt ++;
        printf "Test Case $i Passed\n";
    } else {
        printf "my out put for $i:$stat\n";
	    printf "Test Case $i Failed\n";
    }		
}

if($goodcnt < 4){
    print "All testcases did not pass, try again\n";
} else {
    print "All testcases passed\n";
}
