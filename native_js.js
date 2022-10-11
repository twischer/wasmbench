let tmp, a = 0, b = 1;

console.log('Started!');
  
const t1 = Date.now();

for (let i = 0; i < 10000; ++i) {
  	for (let j = 0; j < 1000000; ++j) {
      	tmp = b;
        b = a + b;
        a = tmp;
    }
}

const t2 = Date.now();
const dt = t2 - t1;

console.log('Finished!');

console.log(`Result: ${b}`);
console.log(`Time: ${0.001 * dt}s`);

