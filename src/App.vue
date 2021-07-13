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
      <base-button text="测试" :btnClick="test"></base-button>

    </div>
    <div class="">  
      {{message}}
    </div>
    <!-- <calendar :setTime="date" @changeTime="setMsg"></calendar> -->
    <calendar v-model="date"></calendar>
    <div>
      <base-dropdown selectName="测试" :optionMsg="opt"></base-dropdown>
    </div>
    <div>
      <test-layout></test-layout>
    </div>
  </div>
</template>

<script>
import calendar from './components/calendar.vue'
import BaseButton from './components/BaseButton.vue'
import BaseDropdown from './components/BaseDropDown.vue'
import testLayout from './components/testLayout.vue'
export default {
  name: 'App',
  components: {
    calendar,
    BaseButton,
    BaseDropdown,
    testLayout
  },
  data(){
    return {
      date:[2021,6,1],
      opt:["第一","第二","第三","第四","第五"],
     // message:"",
      year:null,
      month:null,
    }
  },
  computed:{
    message(){
      //this.date=val;
      return this.date[0]+"年"+this.date[1]+"月"+this.date[2]+"日";
      //console.log(typeof(year))
    }
  },
  methods:{
    setMsg(val){
      this.date=val;
      //this.message=this.date[0]+"年"+this.date[1]+"月"+this.date[2]+"日";
      //console.log(typeof(year))
    },
    test(){
      window.alert("点击");
      this.date=[2000,1,1]
    }
  },
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
  display: flex;
  flex-direction:column;
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
