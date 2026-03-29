const hour = document.getElementById('hour');
const minute = document.getElementById('minute');
const second = document.getElementById('second');
const start = document.getElementById('start');
const stop = document.getElementById('stop');
const reset = document.getElementById('reset');

let hrval = Number(hour.innerText);
let minval = Number(minute.innerText);
let secval = Number(second.innerText);

let timer = null;

const updatetime = () => {
  secval++;

  if (secval === 60) {
    secval = 0;
    minval++;
  }

  if (minval === 60) {
    minval = 0;
    hrval++;
  }

  second.textContent = secval < 10 ? "0" + secval : secval;
  minute.textContent = minval < 10 ? "0" + minval : minval;
  hour.textContent   = hrval < 10 ? "0" + hrval : hrval;
};

start.onclick = () => {
  if (timer === null) {
    timer = setInterval(updatetime, 1000);
  }
};
stop.onclick = () => {
  clearInterval(timer);
  timer = null;
};

reset.onclick=()=>{
  clearInterval(timer);
  timer=null;
  hrval=0;
  minval=0;
  secval=0;
  second.textContent="00";
  minute.textContent="00";
  hour.textContent="00";
  
};