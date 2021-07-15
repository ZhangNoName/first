<template>
  <div >
    <label>{{ selectName }}：</label>
    <select class="select" name="" id="">
      <option value=" " label=" "></option>
      <option
        class="opt"
        v-for="(item, index) in optionMsg"
        :key="index"
        :label="item"
        :value="item"

      ></option>
    </select>
  </div>
</template>

<script>
export default {
  props: {
    optionMsg: {
      type: [Array, String],
      required: false,
      default: () => {
        return [" "];
      },
    },
    selectName: {
      type: String,
      required: true,
    },
  },
};
</script>

<style scoped>
.select{
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
.select:focus{
  border-color: rgb(64, 158, 255);
}
.opt{
  height: 40px;
  font-size: 14px;
  color: rgb(96,98,102);
  line-height: 40px;
  text-align: right;
}
.opt:hover{
  background-color: rgb(96,98,102);
  
}
</style>
