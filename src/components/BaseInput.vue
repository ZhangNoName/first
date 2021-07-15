<template>
  <div>
    <label  class="base-input-label" :for="labelText">{{labelText}}：</label>
    <input 
      class="base-input"
      :value="inputValue"
      :step="step"
      :type="inputType" 
      :id="labelText" 
      :placeholder="tip"
      :pattern="limit"
      @input="checkNumberRange($event)"
      @blur="$emit('inputEnd',$event.target.value)"
    />
    <p v-if="false">{{errorMsg}}</p>
    <!-- <input 
      class="base-input"
      v-model="baseInputValue"
      type="text" 
      :id="labelText" 
    /> -->
    
  </div>
</template>

<script>
export default {
  model:{
    porps:'inputValue',
    event:'inputEnd'
  },
  props:{
    labelText:{
      type:String,
      require:true, 
    },
    inputType:{
      type:String,
      default:()=>{
        return 'text'
      }
    },
    placeHolder:{
      type:String,
      default:()=>{
        return ""
      }
    },
    inputValue:{
      type:String,
    },
    min:{
      type:Number,
    },
    max:{
      type:Number,
    },
    step:{
      type:Number,
    },
    limit:{
      type:Function,
      default:()=>{
        return ()=>{}
      }
    },
    tip:{
      type:String,
      default:()=>{
        return ""
      }
    }
  },
  computed:{
    // baseInputValue:{
    //   get(){
    //     let value=this.inputValue;
    //     return value;
    //   },
    //   set(newVal){
    //     this.$emit('inputEnd',newVal);
    //     console.log("已发送"+newVal);
    //     return newVal;
    //   }
    // }
  },
  methods:{
    checkNumberRange(e){
      //console.log("执行"+val)
      if(this.max && e.target.value>this.max){
        //console.log("大于"+e.target.value+",此时max为"+this.max);
        e.target.value=this.max;
        //console.log("交换过后"+val)
      }
      if( e.target.value<this.min){
        //console.log("小于"+val);
        e.target.value=this.min;
      }
    }
  }

  
}
</script>

<style scoped>
.base-input{
  border: 1px solid rgb(220,223,230);
  outline: none;
  padding-right: 30px;
  padding-left: 15px;
  color: rgb(96, 98, 102);
  font-size: 14px;
  height: 40px;
  line-height: 14px;
  text-align: start;
  widows: 180px;
  border-radius: 4px;
  margin-left: 12px;
}
.base-input:focus{
  border-color: rgb(64, 158, 255);
}
.base-input-label{
  height: 40px;
  font-size: 14px;
  color: rgb(96,98,102);
  line-height: 40px;
  text-align: right;

}
</style>