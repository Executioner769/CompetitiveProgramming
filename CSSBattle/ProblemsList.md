![Objective Pattern](28012024.png)

```
<body>
  <div class="bar hbar1"></div>
  <div class="bar vbar1"></div>
  <div class="bar hbar2"></div>
  <div class="bar vbar2"></div>
</body>
<style>
  div.bar {
    position: absolute;
    background: #F7BED9;
    border-radius: 30px;
  }

  body {
    display: grid;
    place-items: center;
    background: #6F234F;
  }

  div.hbar1 {
    width: 210px;
    height: 30px;
  }
  div.vbar1 {
    height: 210px;
    width: 30px;
  }
  div.hbar2 {
    width: 150px;
    height: 30px;
    rotate: 45deg;
  }
  div.vbar2{
    height: 150px;
    width: 30px;
    rotate: 45deg;
  }
</style>
```

