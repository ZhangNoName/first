export default {
  install (Vue) {
    Vue.directive('loadMore', {
      inserted : function (el, binding){
        const SELECTION_DOM = el.querySelector(".el-select-dropdown .el-select-dropdown__wrap")
        if(SELECTION_DOM){
          SELECTION_DOM.addEventListener('scroll', function () {
            const condition = this.scrollHeight - this.scrollTop -1 <= this.clientHeight
            if(condition){
              binding.value()
            }
          })
        }
      }
    })
  }
}