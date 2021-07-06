<template>
  <div id="app">
    <div class="w-50">
      <label class="" >年：</label>
      <input type="number" v-model="year" class="input">
      <label class="ml-10">月：</label>
      <input type="number" oninput="if(value>12)value=12;if(value<1)value=1" v-model="month" class="input">
      <!-- <label class="">日：</label>
      <input type="number"> -->
      <button @click="setMsg([parseInt(year),parseInt(month) ,1])" class="ml-10">跳转</button>

    </div>
    <div class="">  
      {{message}}
    </div>
    <calendar :setTime="date" @changeTime="setMsg"></calendar>
  </div>
</template>

<script>
import calendar from './components/calendar.vue'

export default {
  name: 'App',
  components: {
    calendar
  },
  data(){
    return {
      date:[2021,6,1],
      message:"",
      year:null,
      month:null,
    }
  },
  methods:{
    setMsg(val){
      this.date=val;
      this.message=this.date[0]+"年"+this.date[1]+"月"+this.date[2]+"日";
      //console.log(typeof(year))
    }
  },
  watch:{
  }
}
</script>

<style>
#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
}
.input{
  @apply w-36 border-solid border-black border-2 rounded;
  @apply focus:ring-2
}
input::-webkit-outer-spin-button,
input::-webkit-inner-spin-button {
  -webkit-appearance: none;
}
input[type="number"] {
  -moz-appearance: textfield;
}
</style>
