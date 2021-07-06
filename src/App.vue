<template>
  <div id="app">
    <div class="">  
      {{message}}
    </div>
    <calendar  @changeTime="setMsg"></calendar>
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
      date:[],
      message:"",
    }
  },
  methods:{
    setMsg(val){
      this.date=val;
      this.message=this.date[0]+"年"+this.date[1]+"月"+this.date[2]+"日";
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
</style>
