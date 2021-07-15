<template>
  <button class="btn"  v-debounce="[btnClick,'click',1000]">{{ text }}</button>
</template>

<script>
import {Debounce} from '../views/Debounce'
export default {
  props: {
    text: {
      type: String,
      required: true,
    },
    btnClick: {
      type: Function,
      required: true,
    },
  },
  methods: {
    selfClick(){
      Debounce(this.btnClick,1000)
    },
    leftClick(){

    }
    //leftClick:Debounce(this.btnClick(),1000)
    
  },
};
</script>

<style>
.btn {
  width: auto;
  font-size: 14px;
  text-align: center;
  line-height: 14px;
  outline: none;
  color: rgb(96, 98, 82);
  margin-left: 10px;
  border: 1px solid transparent;
  border-radius: 4px;
  border-width: 1px;
  border-color: rgb(220, 223, 230);
  padding: 12px 20px 12px 20px;
}
.btn:hover {
  background-color: rgb(64, 158, 255);
  color: white;
}
</style>
