// Nils Fenske
// debtStats class code
// 1/10/2016

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P1 {

    public class debtStats {

        private int _id;

        private int _loans;

        private int _grants;

        private int _startDate;

        private int _graduation;

        private int _amountPaid;

        private bool _status;

        private bool _gradExtend;

        private bool _loanIncrease;
        public bool loanIncrease
        {
            get
            {
                return _loanIncrease;
            }
        }

        private bool _loanDecrease;
        public bool loanDecrease
        {
            get
            {
                return _loanDecrease;
            }
        }

        private int[] _loanArr;

        private int[] _grantArr;

        private int _loanCount;

        private int _grantCount;

        private void resizeLoans()
        {

            int initialSize = _loanArr.Length;

            int[] tempArr = new int[initialSize];

            for (int i = 0; i < initialSize; i++)
            {

                tempArr[i] = _loanArr[i];
            }

            _loanArr = new int[initialSize * 2];

            for (int i = 0; i < initialSize; i++)
            {

                _loanArr[i] = tempArr[i];
            }
        }

        private void resizeGrants()
        {

            int initialSize = _grantArr.Length;

            int[] tempArr = new int[initialSize];

            for (int i = 0; i < initialSize; i++)
            {

                tempArr[i] = _grantArr[i];
            }

            _grantArr = new int[initialSize * 2];

            for (int i = 0; i < initialSize; i++)
            {

                _grantArr[i] = tempArr[i];
            }
        }

        public debtStats(int i, int s, int g)
        {

            _id = i;
            _startDate = s;
            _graduation = g;
            _status = true;
            _loans = 0;
            _grants = 0;
            _gradExtend = false;
            _loanIncrease = false;
            _loanDecrease = false;
            _amountPaid = 0;
            _loanArr = new int[10];
            _grantArr = new int[10];
            _loanCount = 0;
            _grantCount = 0;
        }

        public int debtTotal()
        {

            if (_status) { return _loans; }

            return 0;
        }

        public void addLoan(int x)
        {

            if (_status)
            {
            
                if (!_loanIncrease) { _loanIncrease = true; }

                _loans = _loans + x;
                _loanCount++;

                if (_loanCount == _loanArr.Length) { resizeLoans(); }

                _loanArr[_loanCount - 1] = x;
            }
        }

        public int loanTotal()
        {
            return _loans;
        }

        public void addGrant(int x)
        {

            if (_status)
            {

                _grants = _grants + x;
                _grantCount++;

                if (_grantCount == _grantArr.Length) { resizeGrants(); }

                _grantArr[_grantCount - 1] = x;
            }
        }

        public void extendGraduation(int numYears)
        {

            if (_status)
            {

                _graduation += numYears;

                if (!_gradExtend) { _gradExtend = true; }
            }
        }

        public void makePayment(int payment)
        {

            if (_status)
            {
                _loans -= payment;
                if (!_loanDecrease) { _loanDecrease = true; }

                _amountPaid += payment;
            }
        }

        public bool testThreshold(int x)
        {
            return _loans > x;
        }

        public void deactivate()
        {

            _status = false;
        }

    }
}
