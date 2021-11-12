<template>
  <div v-loading='tableLoading'>
    <el-table
      id="table"
      ref="table"
      :data="visualTableData"
      highlight-current-row
      height="460px"
      row-key="index"
      style="width:100%">
        <el-table-column
          type="selection"
          width="30px"
          reserve-selection>
        </el-table-column>
        <el-table-column
          label="序号"
          prop="index"
          min-width="40px">
        </el-table-column>
        <el-table-column
          label="名称"
          prop="name"
          min-width="100px">
        </el-table-column>

    </el-table>
  </div>
</template>

<script>
export default {
  data () {
    return {
      tableData : [],
      scrollTop : 0,
      startIndex : 0,
      num : 20,
      tableLoading : false,
    }
  },
  computed : {
    visualTableData () {
      return this.tableData.slice(this.startIndex, this.startIndex + this.num)
    }
  },
  watch : {
    scrollTop (val) {
      this.calcList(val)
    }
  },
  methods : {
    calcList (top = this.scrollTop) {
      let height = this.tableData.length * 22
      this.startIndex = Math.floor(top/22)
      let table = this.$refs.table.$el.getELementsByClassName('el-table__body')
      Array.from(table).forEach(v => {
        v.style.height = height + 'px'
        if(this.startIndex + this.num >= this.tableData.length){
          v.style.scrollTop = top > 22 ? (this.scrollTop - 22 + 'px') : 0
          v.style.paddingBottom = 0
        }else{
          v.style.scrollTop = top + 'px'
          v.style.paddingBottom = height - this.num * 22 - top + 'px'
        }
      })
    }
  }
}
</script>