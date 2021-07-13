<template>
  <div>
    <label>{{ selectName }}：</label>
    <select name="" id="">
      <option
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

<style scoped></style>
